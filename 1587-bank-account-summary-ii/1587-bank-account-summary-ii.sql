# Write your MySQL query statement below
select u.name as name, sum(t.amount) as balance
from transactions t
inner join users u
    using (account)
group by u.account
having sum(t.amount) > 10000;