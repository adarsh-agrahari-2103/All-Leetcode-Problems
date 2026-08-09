# Write your MySQL query statement below


WITH city AS
(SELECT customer_number, COUNT(order_number) AS NumOrd
FROM Orders
GROUP BY customer_number)

SELECT customer_number
FROM city 
WHERE NumOrd = (SELECT Max(NumOrd) FROM city)