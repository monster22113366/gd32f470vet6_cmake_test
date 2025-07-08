(1) stm32cubemx成cmake工程
(2) 在根目录的CMakeLists.txt中 
    1-在中间添加 
        include("cmake/gcc-arm-none-eabi.cmake")
    2-在结尾添加
        # 添加后处理命令生成bin和hex文件
        add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> bin/${CMAKE_PROJECT_NAME}.bin
            COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> bin/${CMAKE_PROJECT_NAME}.hex
            COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
            COMMENT "生成二进制和HEX文件，显示内存使用情况"
        )
        以便自动在build/bin中自动生成bin hex文件

(3) 修改cmake/gcc-arm-none-eabi.cmake,添加
        # 输出目录设置
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
        以便将elf文件生成到build/bin

(4)添加openocd.cfg  run.sh  .clangd .vscode文件夹 ，并修改对应的工具链路径，项目名称