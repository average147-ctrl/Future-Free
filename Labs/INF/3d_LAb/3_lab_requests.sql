 -- Задание 5:
 -- номер 1
 SELECT due_date, priority , title
 FROM tasks;

 -- номер 2
SELECT users.name, tasks.title
FROM users
INNER JOIN tasks
ON users.id = tasks.id;

-- номер 3
SELECT title, due_date, priority
FROM tasks
WHERE (priority = 'Высокий')  AND (due_date Between '2025-11-20' And '2025-11-29');

-- Номер 4

SELECT status, COUNT(title) 
FROM tasks
GROUP BY status;