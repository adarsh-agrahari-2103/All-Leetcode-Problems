# Write your MySQL query statement below

SELECT *, CASE WHEN X+Y>Z AND Y+Z>X AND X+Z>Y THEN 'Yes'
ELSE 'No' END AS triangle
FROM triangle 
