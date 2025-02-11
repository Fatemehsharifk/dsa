cmake_minimum_required(VERSION 3.10)

# نام پروژه
project(Avll)

# تنظیم استاندارد C++
set(CMAKE_CXX_STANDARD 17)

# تنظیم مسیر فایل‌های هدر
include_directories(${CMAKE_SOURCE_DIR}/include)

# جمع‌آوری فایل‌های سورس از پوشه src
set(SOURCES
        src/main.cpp
        src/AVLTree.cpp
        src/StudentInsert.cpp
        src/StudentRemover.cpp
        src/StudentSearcher.cpp
)

# جمع‌آوری فایل‌های هدر از پوشه include
set(HEADERS
        include/AVLTree.h
        include/StudentInsert.h
        include/StudentRemover.h
        include/StudentSearcher.h
)

# ایجاد فایل اجرایی
add_executable(Avll ${SOURCES} ${HEADERS})
