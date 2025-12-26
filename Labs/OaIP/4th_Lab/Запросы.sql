-- 1) Найти 5 одногруппников студента (2 до и 3 после по student_id)
SELECT * FROM students 
WHERE group_number = 'ГРУППА-101' 
  AND student_id BETWEEN 3-2 AND 3+3 
  AND student_id != 3
ORDER BY student_id
LIMIT 5;

-- 2) Средний балл конкретного студента через представление
SELECT * FROM student_avg_grades WHERE student_id = 1;

-- 3) Средний балл по предмету "Информатика"
SELECT 
    s.subject_name,
    ROUND(AVG(g.grade), 2) as avg_grade
FROM grades g
JOIN subjects s ON g.subject_id = s.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_name;

-- 4) Полнотекстовый поиск заметок по слову "Информатика"
SELECT * FROM notes 
WHERE to_tsvector('russian', note_text) @@ to_tsquery('russian', 'Информатика');

-- 5) Обновление посещаемости через транзакцию
BEGIN;
UPDATE attendance 
SET status = true 
WHERE student_id = 1 
  AND date_attended = '2024-01-10';
COMMIT;