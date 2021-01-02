public class MainEmail {
    public static void main(String[] args){
        Email e1 = new Email("Leonardo");
        Email e2 = new Email("Donatello");
        Email e3 = new Email("@tartarugas.ninja.com");
        Email e4 = new Email("Michlangelo");
        Email e5 = new Email("Raphael");
        System.out.println(Email.getTotalEmails());
        System.out.println(e1.getEmail());
        System.out.println(e2.getEmail());
        System.out.println(e3.getEmail());
        System.out.println(e4.getEmail());
        System.out.println(e5.getEmail());
        
    }
}
