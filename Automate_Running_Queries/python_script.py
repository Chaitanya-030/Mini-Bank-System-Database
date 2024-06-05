import psycopg2
from tabulate import tabulate

def run_sql_query(query):
    try:
        # Here we connect to a postgresql
        conn = psycopg2.connect(
            dbname="",
            user="",
            password="",
            host="",
            port=""
        )

        # Create a cursor object
        cur = conn.cursor()

        # Execute the SQL query
        cur.execute(query)

        # Fetch column names
        col_names = [desc[0] for desc in cur.description]

        # Fetch all the rows
        rows = cur.fetchall()

        # Print the result in a tabular format
        print(tabulate(rows, headers=col_names, tablefmt="pretty"))

    except psycopg2.Error as e:
        print("Error connecting to PostgreSQL database:", e)

    finally:
        # Close the cursor and connection
        if cur:
            cur.close()
        if conn:
            conn.close()

# Example SQL query to get transactions of the day
sql_query = """
set search_path to minibanksys;
select * from transaction where accountno = 'ACC001' order by amount desc limit 10;
"""

# Run the SQL query and print the result in a tabular format
run_sql_query(sql_query)
