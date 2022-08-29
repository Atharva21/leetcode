# Write your MySQL query statement below
select p.patient_id, p.patient_name, p.conditions
from Patients as p
where p.conditions regexp '\\bDIAB1';