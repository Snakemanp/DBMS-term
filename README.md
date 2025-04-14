# 📁 DBMS-Term Project  
**SQL Query Parsing and Optimization**

---

## 👥 Team Members
- **Preetham Battula**
- **Sumith Chandra**  
  [GitHub: sumith2425](https://github.com/sumith2425)
- **Sathvik Pratapgiri**
- **Kasyap Kovvuru**  
  [GitHub: kovvurukasyap](https://github.com/kovvurukasyap)
- **Jayanth Reddy**

---

## 📚 Course Details
- **Course**: CS30202 - Database Management Systems  
- **Semester**: Spring 2025  
- **Institute**: IIT Kharagpur

---

## 🧩 Problem Statement

Design a system capable of processing SQL-like queries by:
- Performing **lexical** and **syntactic analysis** using **Flex** and **Bison**.
- Generating **relational algebra trees** to represent query execution plans.
- Applying **query optimization techniques** inspired by *Silberschatz’s DBMS textbook*.
- Estimating the **execution cost** based on tuples and operations.

---

## 🎯 Goals

1. **Lexical and Syntax Analysis**  
   - Tokenize and parse SQL queries using **Flex** and **Bison**.
   - Transform into structured intermediate forms (Relational Algebra Trees).

2. **Generate Computation Graphs**  
   - Construct and display the logical execution plan as a relational algebra tree.

3. **Query Optimization**  
   - Apply standard techniques:
     - Selection Pushdown
     - Projection Pushdown
     - Join Reordering

4. **Cost Estimation & Plan Selection**  
   - Estimate costs based on:
     - Number of tuples
     - Types of operations
     - Operator depth  
   - Select the **least-cost** tree as the optimal plan.

---

## ⚙️ How It Works

### 🧾 Parsing
- **Flex** scans SQL tokens (keywords, identifiers, operators, literals).
- **Bison** applies grammar rules to structure queries and build the **relational algebra tree**.

### 🌳 Relational Algebra Tree
- Built as binary trees where each node represents a relational operator.
- Internal nodes: Join, Select, Project, etc.
- Leaf nodes: Base tables.

### 📈 Optimization
- Multiple transformation passes generate **equivalent trees** using:
  - **Selection Pushdown**
  - **Projection Pushdown**
  - **Join Reordering**  
- A limit is set to prevent excessive trees: `MAX_RES_TREES = 25`.

### 💰 Cost Estimation
- Cost heuristics applied:
  - Joins are costlier.
  - Projection cost = 0 (unless `DISTINCT` is specified).
  - Writes (Insert/Update/Delete) = 2 × Block Transfer Cost.
- Tree with lowest cost is selected.

---

## 🗃️ Metadata

Read from `documentation.txt` during startup.

**Used for**:
- Validating table and column names
- Optimization decisions (e.g., join reordering, pushdowns)
- Schema-aware transformations

### 📄 Sample Tables:
```text
1. instructor ( ID , name , dept_name , salary )
2. teaches ( ID , course_id , sec_id , semester , year )
3. course ( course_id , title , dept_name , credits )
