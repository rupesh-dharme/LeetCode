# Write your MySQL query statement below
SELECT Customers.name AS Customers FROM Customers
WHERE
Customers.id NOT IN (SELECT Orders.customerId from Orders);