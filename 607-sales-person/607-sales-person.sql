# Write your MySQL query statement below

select s.name as name
from orders o
inner join company c
    on (o.com_id = c.com_id and c.name = 'red')
right join salesperson s
    using (sales_id)
where o.sales_id is null;