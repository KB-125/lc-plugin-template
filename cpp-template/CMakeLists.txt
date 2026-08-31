cmake_minimum_required(VERSION 3.29)
project(cpp_template)

set(CMAKE_CXX_STANDARD 17)

# 让 IDE（VS 解决方案资源管理器 / CMake Tools 面板）按 FOLDER 属性分组显示 target
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ---------- 公共代码 -> 静态库 ----------
# CONFIGURE_DEPENDS: 插件新下载/新建的题目文件无需手动重新 configure，build 时自动重新扫描
file(GLOB_RECURSE COMMON_SOURCES CONFIGURE_DEPENDS "leetcode/editor/common/*.cpp")
add_library(common STATIC ${COMMON_SOURCES})
set_target_properties(common PROPERTIES FOLDER "common")

# ---------- 每个解题文件 -> 一个可执行文件 ----------
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS
     "leetcode/editor/cn/*.cpp"
     "leetcode/editor/en/*.cpp")

foreach(source_file IN LISTS MAIN_SOURCES)
    get_filename_component(dir "${source_file}" DIRECTORY)

    # 分组名 = editor 下的子目录，如 "cn" / "en"
    file(RELATIVE_PATH group "${CMAKE_SOURCE_DIR}/leetcode/editor" "${dir}")

    # 目标名 = 目录前缀 + 题目 slug，如 "cn_two-sum"，短且 cn/en 天然去重
    get_filename_component(title "${source_file}" NAME_WE)
    set(target "${group}_${title}")

    # 兜底：万一未来新增语言目录导致同名冲突，退化为完整相对路径名
    if(TARGET "${target}")
        file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}/leetcode" "${source_file}")
        string(REPLACE "/" "_" target "${rel}")
        string(REGEX REPLACE "\\.cpp$" "" target "${target}")
    endif()

    add_executable(${target} "${source_file}")
    target_link_libraries(${target} PRIVATE common)

    # 在 target 面板 / VS 方案视图中按 "leetcode/cn"、"leetcode/en" 分组
    set_target_properties(${target} PROPERTIES FOLDER "leetcode/${group}")
endforeach()
