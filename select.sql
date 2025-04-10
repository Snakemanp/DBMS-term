SELECT i.name, salary
FROM instructor i
JOIN teaches t ON i.ID = t.ID
WHERE i.salary > 100000;

SELECT c.dept_name, c.credits
FROM instructor i
JOIN teaches t ON i.ID = t.ID
JOIN course c ON t.course_id = c.course_id;