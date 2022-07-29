# Write your MySQL query statement below

select user_id as buyer_id, join_date, sum(if(year(order_date) = '2019', 1, 0)) as orders_in_2019
from users u
left join orders o
    on u.user_id = o.buyer_id
group by user_id