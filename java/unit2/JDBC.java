imort java.sql.*

public class JDBC {

    // jdbc driver and database url
    static final String JDBC_DRIVER = 'com.mysql.jdbc.Driver';
    static final String DB_URL = 'jdbc:mysql://localhost/EMP';

    // username and password
    static final String USER = '0xelectron';
    static final String PASS = 'PASS';

    public static void main(String[] args) {

        Connection cn = null;
        Statement st = null;

        try {

            Class.forName(JDBC_DRIVER);

            System.out.println("Connecting to database...");
            cn = DriverManager.getConnection(DB_URL, USER, PASS);

            System.out.println("Creating statement");
            st = cn.CreateStatement();

            String sql = 'UPDATE Employees set age=30 WHERE id=103';
            int i = st.executeUpdate(sql);
            System.out.println(i + "records updated");
            

        }
    }
}
