# Hex Dump Utility

A lightweight C-based utility that provides a hexadecimal and ASCII representation of any file or data stream. This project was built to explore low-level system calls, memory management, and the "everything is a file" philosophy in Linux. This is a C program that can read the raw bytes of any type of file and display it in Hexadecimal. This program shows us exactly what the CPU sees.

## 🚀 Features

* **Hexadecimal Output:** Displays raw byte values in uppercase hex format.
* **ASCII Translation:** Provides a side-by-side printable character view, using `.` for non-printable bytes.
* **Stream Compatibility:** Works with standard files, device files and pipes.
* **Robust Memory Handling:** Uses unsigned buffers to ensure data integrity.



## 🛠️ Installation & Usage

### Prerequisites

* A C compiler (like `gcc`)
* Unix-based environment (Linux/macOS) 



### Compiling

```bash
gcc -o hex-dump hex-dump.c

```

### Running

To analyze a file:

```bash
./hex-dump <filename>

```


---

## 🧠 What I Learned

This project served as a deep dive into Systems Programming. Below are the key concepts explored in my documentation:

### 1. The Unix I/O Model

I utilized core Unix system calls for resource management:

* **`<stdio.h>`**: For formatted output like `printf()`.


* **`<fcntl.h>`**: For handling `open()` and `close()` operations.


* **`<unistd.h>`**: For performing low-level `read()` and `write()` operations.


* **File Descriptors**: A non-negative integer acting as an abstract handle to an I/O resource.


* **Offsets**: A byte-count integer tracking the current "bookmark" in a file stream.



### 2. Linux Philosophy: "Everything is a File"

I learned that in Linux, a file is essentially a **stream of bytes**. This unified abstraction allows the same code to interact with a hard drive, a keyboard, or a network socket without changing the programming interface.

### 3. Memory & Data Integrity

* **Unsigned vs. Signed**: I used `unsigned char` for the buffer to prevent the compiler from making assumptions about sign extension.


* **Integer Extension**: I observed how the CPU converts 8-bit chars to 32-bit integers. Without the `unsigned` keyword, a byte like `11111111` could be sign-extended to `-1` (), whereas `unsigned` ensures it is zero-extended to  ().



### 4. Robust Datatypes (`size_t` vs `ssize_t`)

* **`size_t`**: An unsigned type used to store very large values, scaling with the word size (32-bit or 64-bit) of the computer.


* **`ssize_t`**: A signed version of `size_t`. It is used for the `read()` function because it can represent the number of bytes read while still being able to return `-1` to signal an error, such as a USB drive being removed abruptly.



---

## 📂 Project Structure

* `hex-dump.c`: The core logic for the hex-dump utility.


* `WhatDidILearn.pdf`: A detailed technical breakdown of the concepts used.

