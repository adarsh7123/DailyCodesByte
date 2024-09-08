# Write your MySQL query statement below
select u.unique_id as unique_id , e.name as name 
from Employees e left Join EmployeeUNI u 
on e.id = u.id;