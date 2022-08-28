# # Write your MySQL query statement below
# select
#     Employees.employee_id, Employees.salary as 'bonus'
# from
#     Employees
# where
#     Employees.employee_id % 2 = 1
#     and
#     Employees.name not like 'M%'
# order by Employees.employee_id
# ;
select
    Employees.employee_id,
    case when
    Employees.employee_id % 2 = 1
    and
    Employees.name not like 'M%'
    then Employees.salary
    else 0
    end  as 'bonus'
from
    Employees
order by Employees.employee_id
