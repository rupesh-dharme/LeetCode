# Write your MySQL query statement below

SELECT sub.employee_id FROM
(   SELECT e.employee_id, name, salary
    FROM Employees AS e
    LEFT JOIN Salaries AS s
    ON e.employee_id = s.employee_id
    
    UNION
    
    SELECT s.employee_id, name, salary
    FROM Employees AS e
    RIGHT JOIN Salaries AS s
    ON e.employee_id = s.employee_id) AS sub
WHERE sub.name IS NULL OR sub.salary IS NULL
ORDER BY sub.employee_id;
