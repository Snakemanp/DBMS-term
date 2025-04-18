SELECT 
    i.ID,
    i.name,
    i.salary,
    w.age,
    c.title,
    c.credits
FROM 
    instructor i
JOIN teaches t ON i.ID = t.ID
JOIN course c ON t.course_id = c.course_id
JOIN workers w ON i.ID = w.ID;

WITH InstructorCourseInfo AS (
    SELECT 
        i.ID,
        i.name,
        i.salary,
        i.dept_name,
        t.course_id,
        t.sec_id,
        c.title,
        c.credits
    FROM 
        instructor i
    JOIN teaches t ON i.ID = t.ID
    JOIN course c ON t.course_id = c.course_id
)
SELECT 
    ici.ID,
    ici.instructor_name,
    ici.instructor_salary,
    ici.dept_name,
    ici.course_id,
    ici.course_title,
    ici.credits,
    w.salary,
    w.age
FROM workers w
JOIN InstructorCourseInfo ici ON ici.ID = w.ID;

SELECT *
FROM course
ORDER BY course.course_id ASC;

INSERT INTO teaches (ID, name, department, age)
VALUES (101, 'Alice', 'CS', 20);

DELETE FROM teaches WHERE ID > 21;

SELECT ID FROM instructor AS c WHERE ID = 4;

SELECT ID AS id FROM instructor JOIN course ON instructor.ID = credits;