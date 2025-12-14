#include <iostream>
#include <pqxx/pqxx> // Подключение библиотеки

int main() {
    try {
        // Строка подключения к базе данных
        std::string conninfo = "host=localhost port=5432 dbname=postgres user=postgres password=";

        // Устанавливаем соединение с базой данных
        pqxx::connection conn(conninfo);

        if (conn.is_open()) {
            std::cout << "Connected to database: " << conn.dbname() << std::endl;
        } else {
            std::cerr << "Failed to connect to the database." << std::endl;
            return 1;
        }

        // Закрываем соединение
        conn.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}








// #include <iostream>
// #include <pqxx/pqxx>
// int main()
// {
//     try
//     {
//         pqxx::connection conn(
//             "host=localhost "
//             "port=5432 "
//             "dbname=postgres "
//             "user=postgres "
//             "password=qwerty"
//         );
//         pqxx::work txn{conn};
//         txn.exec(
//             "CREATE TABLE IF NOT EXISTS users ("
//             "id SERIAL PRIMARY KEY,"
//             "name VARCHAR(100) NOT NULL,"
//             "email VARCHAR(100) UNIQUE NOT NULL,"
//             "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
//             ")"
//         );
//         txn.commit();
//         std::cout << "Таблица создана/уже существует" << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << "Ошибка создания таблицы: " << e.what() << std::endl;
//     }
//     return 0;
// }