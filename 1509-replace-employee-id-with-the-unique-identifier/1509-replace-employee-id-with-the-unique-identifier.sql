# Write your MySQL query statement below
select  e.name as name , u.unique_id as unique_id 
from Employees e left Join EmployeeUNI u 
on e.id = u.id;