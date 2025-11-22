CREATE TABLE tasks(
id INT PRIMARY KEY,
title  VARCHAR(50) UNIQUE,
priority  VARCHAR(50),
due_date DATE,
status  VARCHAR(50)
);

CREATE TABLE users(
id INT PRIMARY KEY,
name  VARCHAR(50) UNIQUE
);

CREATE TABLE task_assignments(
assignment_id INT PRIMARY KEY,
task_id  INT UNIQUE,
user_id INT UNIQUE,
FOREIGN KEY (task_id) REFERENCES tasks(id),
FOREIGN KEY (user_id) REFERENCES users(id)
);

SELECT * 
FROM task_assignments;
SELECT * 
FROM tasks;
SELECT * 
FROM users;





