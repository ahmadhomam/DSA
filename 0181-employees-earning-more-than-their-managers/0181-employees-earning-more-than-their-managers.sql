# Write your MySQL query statement below

SELECT e1.name AS Employee
FROM Employee AS e1
WHERE salary > (
    SELECT salary
    FROM Employee AS e2 
    WHERE id = e1.managerId
) ;