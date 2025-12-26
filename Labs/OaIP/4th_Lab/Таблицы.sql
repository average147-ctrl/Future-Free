-- Таблица студентов
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(10) NOT NULL
);

-- Таблица предметов
CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

-- Таблица оценок
CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    subject_id INT REFERENCES subjects(subject_id),
    grade INT CHECK (grade BETWEEN 2 AND 5)
);

-- Таблица посещаемости
CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    date_attended DATE NOT NULL,
    status BOOLEAN NOT NULL
);

-- Таблица заметок
CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    note_text TEXT NOT NULL
);