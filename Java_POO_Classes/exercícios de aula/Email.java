public class Email {
    private static String dominio = "@dominio.generico.com.br";
    private static int totalEmails = 0;
    private String email;

    private static void changeDominio(String novoDominio){
        dominio = novoDominio;
    }
    
    public Email(String email){
        if (email.charAt(0) == '@'){
            changeDominio(email);
        } else {
            totalEmails += 1;
            this.email = email;
        }
    }

    public String getEmail(){
        return this.email + dominio;
    }

    public static int getTotalEmails(){
        return totalEmails;
    }
}
