# Database Documentation: University Schema

## Schemas

### 1. `instructor` Table
- **Description**: Stores information about university instructors.
- **Columns**:
  - `ID` (Integer, Primary Key): Unique identifier for each instructor.
  - `name` (VARCHAR(50)): Name of the instructor.
  - `dept_name` (VARCHAR(20)): Department name where the instructor works.
  - `salary` (Decimal(10,2)): Annual salary of the instructor.

### 2. `teaches` Table
- **Description**: Records the courses taught by instructors, including section and semester details.
- **Columns**:
  - `ID` (Integer, Foreign Key referencing `instructor.ID`): Instructor identifier.
  - `course_id` (VARCHAR(8), Foreign Key referencing `course.course_id`): Course identifier.
  - `sec_id` (VARCHAR(8)): Section identifier for the course.
  - `semester` (VARCHAR(10)): Semester when the course is taught (e.g., Fall, Spring).
  - `year` (Integer): Year when the course is taught.

### 3. `course` Table
- **Description**: Contains details about the courses offered by the university.
- **Columns**:
  - `course_id` (VARCHAR(8), Primary Key): Unique identifier for each course.
  - `title` (VARCHAR(50)): Title of the course.
  - `dept_name` (VARCHAR(20)): Department offering the course.
  - `credits` (Integer): Number of credits for the course.

## Dummy Data

### `instructor` Table
| ID  | name            | dept_name | salary  |
|-----|-----------------|-----------|---------|
| 101 | Alice Johnson   | Music     | 75000.00|
| 102 | Bob Smith       | Physics   | 80000.00|
| 103 | Clara Evans     | Music     | 72000.00|
| 104 | David Lee       | Biology   | 85000.00|
| 105 | Emma Wilson     | Physics   | 78000.00|
| 106 | Frank Miller    | History   | 70000.00|
| 107 | Grace Brown     | Music     | 74000.00|

### `teaches` Table
| ID  | course_id | sec_id | semester | year |
|-----|-----------|--------|----------|------|
| 101 | MUS101    | S1     | Fall     | 2023 |
| 101 | MUS102    | S2     | Spring   | 2024 |
| 102 | PHY201    | S1     | Fall     | 2023 |
| 103 | MUS101    | S3     | Fall     | 2024 |
| 104 | BIO301    | S1     | Spring   | 2024 |
| 105 | PHY202    | S2     | Spring   | 2023 |
| 106 | HIS401    | S1     | Fall     | 2023 |
| 107 | MUS103    | S1     | Spring   | 2025 |

### `course` Table
| course_id | title              | dept_name | credits |
|-----------|---------------------|-----------|---------|
| MUS101    | Introduction to Music | Music     | 3       |
| MUS102    | Music Theory        | Music     | 4       |
| MUS103    | Advanced Composition| Music     | 3       |
| PHY201    | Classical Mechanics | Physics   | 4       |
| PHY202    | Electromagnetism    | Physics   | 4       |
| BIO301    | Genetics            | Biology   | 3       |
| HIS401    | World History       | History   | 3       |

## Notes
- **Data Characteristics**:
  - The `instructor` table has 7 entries, with multiple instructors in the Music department to allow for testing queries involving department filters.
  - The `teaches` table links instructors to courses, with some instructors teaching multiple courses across different semesters and years (e.g., 2023–2025).
  - The `course` table includes 7 courses across 4 departments, with varying credit values.
- **Integrity Constraints**:
  - `ID` in `teaches` references `ID` in `instructor`.
  - `course_id` in `teaches` references `course_id` in `course`.
  - Foreign key relationships ensure referential integrity.
- **Usage**: This dataset can be used to test query optimization techniques, such as pushing selections (e.g., `dept_name = 'Music'`), join ordering, and cost estimation based on tuple counts and distinct values.

## SQL Creation and Population Scripts

### Create Tables
```sql
CREATE TABLE instructor (
    ID INT PRIMARY KEY,
    name VARCHAR(50),
    dept_name VARCHAR(20),
    salary DECIMAL(10,2)
);

CREATE TABLE teaches (
    ID INT,
    course_id VARCHAR(8),
    sec_id VARCHAR(8),
    semester VARCHAR(10),
    year INT,
    FOREIGN KEY (ID) REFERENCES instructor(ID),
    FOREIGN KEY (course_id) REFERENCES course(course_id)
);

CREATE TABLE course (
    course_id VARCHAR(8) PRIMARY KEY,
    title VARCHAR(50),
    dept_name VARCHAR(20),
    credits INT
);