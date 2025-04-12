SELECT i.name, salary
FROM instructor i
JOIN teaches t ON i.ID = t.ID
WHERE i.salary > 100000;

SELECT i.name, t.course_id, c.title
FROM instructor i
JOIN (teaches t JOIN course c ON t.course_id = c.course_id) ON i.ID = t.ID;

SELECT i.name, c.credits
FROM instructor i
JOIN teaches t ON i.ID = t.ID
JOIN course c ON t.course_id = c.course_id
WHERE i.salary > 100000;

SELECT c.dept_name, c.credits
FROM instructor i
JOIN (SELECT * FROM teaches) t ON i.ID = t.ID
JOIN course c ON t.course_id = c.course_id;

SELECT *
FROM instructor i NATURAL JOIN teaches t, course c
WHERE i.ID = t.ID 
AND t.course_id = c.course_id;

INSERT INTO top_students
SELECT * FROM students WHERE marks > 90;