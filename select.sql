SELECT e.employee_name, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id
WHERE e.salary > 100000 AND d.department_name = 'Engineering';

SELECT e.employee_name, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN projects p ON e.employee_id = p.lead_employee_id;

SELECT e.employee_name, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN projects p ON e.employee_id = p.lead_employee_id
WHERE e.salary > 100000 AND d.department_name = 'Engineering';

SELECT
    e.employee_name,
    p.project_name,
    d.department_name
FROM
    employees e
    JOIN departments d 
        ON e.department_id = d.department_id
    JOIN projects p 
        ON e.employee_id = p.lead_employee_id
WHERE
    d.department_name = 'Engineering'
    AND e.salary > 100000;