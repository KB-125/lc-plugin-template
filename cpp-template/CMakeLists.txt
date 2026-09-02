cmake_minimum_required(VERSION 3.29)
project(cpp_template)

set(CMAKE_CXX_STANDARD 17)

# 题目文件为 UTF-8（无 BOM，由插件生成，含中文注释）。
# MSVC 默认按系统代码页(936/GBK)读取源文件会报 C4819，显式指定源码/执行字符集为 UTF-8
if(MSVC)
    add_compile_options(/utf-8)
endif()

# 让 IDE（VS 解决方案资源管理器 / CMake Tools 面板）按 FOLDER 属性分组显示 target
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ---------- 公共代码 -> 静态库 ----------
# CONFIGURE_DEPENDS: 插件新下载/新建的题目文件无需手动重新 configure，build 时自动重新扫描
file(GLOB_RECURSE COMMON_SOURCES CONFIGURE_DEPENDS "leetcode/editor/common/*.cpp")
add_library(common STATIC ${COMMON_SOURCES})
set_target_properties(common PROPERTIES FOLDER "common")

# ---------- 每个解题文件 -> 一个可执行文件 ----------
# 目录约定（由 LeetCode 插件的 labuladong-leetcode.filePath 配置生成）：
#   leetcode/editor/cn/<题型tag>/<题号>.<难度>.<题名slug>.cpp
#   例: leetcode/editor/cn/hash-table/1.easy.two-sum.cpp
# target 命名: cn_<tag>_<难度>_<题号>_<slug>，例: cn_hash-table_easy_1_two-sum
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS "leetcode/editor/cn/*.cpp")

foreach(source_file IN LISTS MAIN_SOURCES)
    get_filename_component(dir "${source_file}" DIRECTORY)
    get_filename_component(tag "${dir}" NAME)

    # 从文件名解析 题号.难度.题名（缺失难度等旧命名格式也能优雅降级）
    # 注意：NAME_WE 会在第一个点处截断（1.easy.two-sum.cpp -> 1），故用 NAME 手动剥后缀
    get_filename_component(fname "${source_file}" NAME)
    string(REPLACE ".cpp" "" fname "${fname}")
    string(REPLACE "." ";" toks "${fname}")
    list(LENGTH toks ntoks)

    if(ntoks GREATER_EQUAL 3)
        list(GET toks 0 qid)
        list(GET toks 1 diff)
        list(REMOVE_AT toks 0 1)
        string(JOIN "." slug ${toks})
        set(target "cn_${tag}_${diff}_${qid}_${slug}")
    elseif(ntoks EQUAL 2)
        list(GET toks 0 qid)
        list(GET toks 1 slug)
        set(target "cn_${tag}_${qid}_${slug}")
    else()
        set(target "cn_${tag}_${fname}")
    endif()

    # 兜底：万一重名（如同一题在多个 tag 目录各有文件），退化为完整相对路径名
    if(TARGET "${target}")
        file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}/leetcode" "${source_file}")
        string(REPLACE "/" "_" target "${rel}")
        string(REPLACE ".cpp" "" target "${target}")
    endif()

    add_executable(${target} "${source_file}")
    target_link_libraries(${target} PRIVATE common)

    # 在 target 面板 / VS 方案视图中按 leetcode/cn/<tag> 分组
    set_target_properties(${target} PROPERTIES FOLDER "leetcode/cn/${tag}")
endforeach()
