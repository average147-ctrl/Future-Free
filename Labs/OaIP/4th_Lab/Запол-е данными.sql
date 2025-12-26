-- Добавление 6 студентов одной группы
INSERT INTO students (full_name, group_number) VALUES
('Иванов Иван Иванович', 'ГРУППА-101'),
('Петров Петр Петрович', 'ГРУППА-101'),
('Сидорова Анна Сергеевна', 'ГРУППА-101'),
('Кузнецов Алексей Владимирович', 'ГРУППА-101'),
('Смирнова Ольга Дмитриевна', 'ГРУППА-101'),
('Васильев Денис Игоревич', 'ГРУППА-101');

-- Добавление 3 предметов
INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

-- Добавление оценок (по 3 оценки каждому студенту по каждому предмету)
INSERT INTO grades (student_id, subject_id, grade)
SELECT s.student_id, subj.subject_id, 
       CASE 
           WHEN random() < 0.3 THEN 4
           WHEN random() < 0.6 THEN 5
           ELSE 3
       END
FROM students s
CROSS JOIN subjects subj;

-- Добавление посещаемости на два дня
INSERT INTO attendance (student_id, date_attended, status)
SELECT student_id, '2024-01-10', 
       CASE WHEN random() < 0.8 THEN true ELSE false END
FROM students
UNION ALL
SELECT student_id, '2024-01-12',
       CASE WHEN random() < 0.9 THEN true ELSE false END
FROM students;

-- Добавление заметок для каждого студента
INSERT INTO notes (student_id, note_text) VALUES
(1, 'Любит информатику'),
(2, 'Нужна помощь по информатике'),
(3, 'Редко посещает занятия по информатике'),
(4, 'Отличник по всем предметам'),
(5, 'Хорошо работает в команде'),
(6, 'Прогресс по информатике');