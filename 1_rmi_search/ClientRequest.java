
// Java program for client application

import java.rmi.Naming;

public class ClientRequest {
    public static void main(String[] args) {
        String answer, value = "Reflection in Java321321";
        try {
            // lookup method to find reference of remote object
            Search access = (Search) Naming.lookup("rmi://localhost:2000" +
                    "/LP-V");
            answer = access.query(value);
            System.out.println("Article on " + value +
                    " " + answer + " at LP-V");
        } catch (Exception ae) {
            System.out.println(ae);
        }
    }
}
