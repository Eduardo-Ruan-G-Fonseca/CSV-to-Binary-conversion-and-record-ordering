# README - Practical Project on Sorting in C++

## Overview
This project is a practical implementation of sorting algorithms using binary files in C++. It includes functions for converting CSV data into a binary format and then performing various operations such as insertion, deletion, searching, and sorting. The project was developed as part of the **Data Structures - GAC108** course at the **Federal University of Lavras (UFLA)**.

## Project Structure
The project consists of multiple C++ files implementing different functionalities:

1. **CSV to Binary Conversion**:
   - Reads a CSV file and converts its content into a binary format.
   - Utilizes C++ file handling libraries such as `fstream` and `sstream`.
   - Stores data in a structured format.

2. **Binary File Manipulation**:
   - Implements a menu-driven interface for various operations.
   - Allows the user to insert, delete, update, search, and view records.

3. **Sorting Algorithms Implementation**:
   - Uses **Merge Sort** and **Quick Sort** for sorting the records.
   - External sorting techniques are employed for large datasets.

## Features
### 1. CSV to Binary Conversion
- Reads a CSV file and extracts data fields.
- Converts the fields into structured binary format.
- Utilizes a record structure with multiple fields.

### 2. Binary File Manipulation
The program provides a menu with the following functionalities:

#### **Option 1: Print All Records**
- Displays all stored records from the binary file.
- Skips records marked as deleted.

#### **Option 2: Insert a New Record**
- Allows the user to insert a new entry at the beginning, end, or a specific position in the file.
- If a deleted record exists, it is overwritten instead of appending new data.

#### **Option 3: Delete a Record**
- Marks a record as deleted instead of physically removing it.

#### **Option 4: Modify an Existing Record**
- Allows the user to modify a specific record's data.

#### **Option 5: Search for a Record**
- Enables searching by different fields.

#### **Option 6: Sort Records**
- Provides sorting options using:
  - **Merge Sort** for external sorting.
  - **Quick Sort** for in-memory sorting.

#### **Option 7: Export Data to CSV**
- Converts binary data back to CSV format.

## Sorting Algorithm Details
### Merge Sort Implementation
- The file is split into smaller sorted blocks.
- Blocks are merged iteratively until the full file is sorted.
- Used for handling large files efficiently.

### Quick Sort Implementation
- Uses the partitioning method with a pivot.
- Recursively sorts smaller partitions.
- Used for in-memory sorting when data fits within memory limits.

## Challenges and Learnings
During the development, we encountered the following challenges:
- Handling spaces in character fields, which initially caused misalignment in records.
- Implementing efficient external sorting to handle large binary files.
- Managing file pointer operations to avoid data corruption.

## Conclusion
This project provided hands-on experience in handling structured binary files, implementing sorting algorithms, and managing file-based data efficiently. The integration of **Merge Sort** and **Quick Sort** demonstrated how different sorting approaches apply to various data sizes and memory constraints.

## Authors
- Matheus de Paula Megale
- Eduardo Ruan Guimarães Fonseca
- Lucas de Oliveira Pereira
