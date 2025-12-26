-- Индексы
CREATE INDEX idx_students_group ON students(group_number);
CREATE INDEX idx_grades_student ON grades(student_id);
CREATE INDEX idx_notes_search ON notes USING GIN(to_tsvector('russian', note_text));

-- Представление для среднего балла
CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    ROUND(AVG(g.grade), 2) as avg_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name;

-- Транзакция для добавления нового студента с оценками
BEGIN;

INSERT INTO students (full_name, group_number) 
VALUES ('Новиков Максим Андреевич', 'ГРУППА-101')
RETURNING student_id;

INSERT INTO grades (student_id, subject_id, grade)
VALUES 
    (currval('students_student_id_seq'), 1, 5),
    (currval('students_student_id_seq'), 2, 4),
    (currval('students_student_id_seq'), 3, 5);

COMMIT;