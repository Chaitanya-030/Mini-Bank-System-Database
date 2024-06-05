# Mini-Bank-System-Database

In this project, we developed a comprehensive database for a mini bank system, featuring the following tables: Account, Customer, AccountCustomer, Branch, Transactions, and DailyBalance. Our approach began with the careful design of the schema, defining the attributes and tables necessary for the system. Following this, we created an Entity-Relationship (ER) diagram to clearly identify all primary and foreign keys.

The primary objective was to present this database to bank managers, who are non-IT professionals, demonstrating how PostgreSQL and pgAdmin can be utilized to perform CRUD (Create, Read, Update, Delete) operations effectively. To facilitate this, we designed and executed approximately 30-40 queries, showcasing real-life banking scenarios within pgAdmin.

Moreover, we provided training on automating the entire process, from schema creation to executing DDL (Data Definition Language) and DML (Data Manipulation Language) scripts. This included demonstrating how to run queries via batch files using Python scripts, enabling managers to execute queries without the need to open pgAdmin directly.

This project not only delivered a functional database system but also empowered bank managers with the skills to leverage database technologies for enhanced operational efficiency.

*******************************************************************************************************************************************************************

## Steps to run DDL commands and INSERT queries in one go : 
Within the ALL_Scripts folder, there exists a master.sql file. To execute this file using the psql tool within a specific schema, use the command:

\i <path_to_your_file/master.sql>

Executing this command will sequentially run all scripts referenced within the master.sql file. This approach facilitates the creation of the schema, execution of all DDL scripts, and insertion of data through a single operation, eliminating the need to run individual insert commands for each table manually.


*******************************************************************************************************************************************************************

## Automate the running of queries wihtout opening PgAdmin : 
By utilizing the psycopg2 library in Python, database queries can be executed directly through a Python script, bypassing the need to open pgAdmin. This method is especially beneficial in real banking systems where the same query must be run daily to obtain updated results. Additionally, creating a shortcut file (batch file) that triggers the Python script automatically upon execution streamlines the process, ensuring efficiency and consistency in accessing critical data.

In the Automate_Running_Queries folder, you have been provided with a Python script and a batch file. By clicking on the batch file, it will trigger the Python script and run the specified query within the script, further simplifying the process of automating query execution. You can add the details of database like dbname, username, password and host as in your specific case.
