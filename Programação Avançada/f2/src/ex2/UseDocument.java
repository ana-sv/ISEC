package ex2;

public class UseDocument
{
    public static void main(String [] args) {
        Document doc = new Document("William Shakespeare Quotes");

        System.out.println(doc);
        System.out.println("\n-------------------------");

        doc.addAuthor("William Shakespeare");
        doc.addAuthor("Name2");
        doc.addAuthor("William Shakespeare");
        doc.addAuthor("Name3");

        doc.addText("this life, which had been the tomb of his virtue and of his honour, is but a walking shadow.");
        doc.addText("a poor player, that struts and frets his hour upon the stage, and then is heard no more.");
        doc.addText("What's in a name?that which we call a rose by any other name would smell as sweet.");
        System.out.println(doc);
        System.out.println("\n-------------------------");

        doc.toUpperCase();
        System.out.println(doc);
        System.out.println("\n-------------------------");

        System.out.println("Number of words: "+doc.countWords());
        System.out.println("Numero of times \"his\" in text: "+doc.countWord("his"));
        System.out.println("\n-------------------------");

        doc.removeAuthor("name2");
        System.out.println("After removing author \"Name2\": "+doc);
        System.out.println("\n-------------------------");

        doc.removeAuthor(2);
        System.out.println("After removing 3rd author: "+doc);
        System.out.println("\n-------------------------");

        doc.removeAuthor(0);
        System.out.println("After removing 1st author: "+doc);
        System.out.println("\n-------------------------");

        doc.removeText(2);
        System.out.println("After removing 3rd text string: "+doc);
        System.out.println("\n-------------------------");

        doc.removeText(0);
        System.out.println("After removing 1st text string: "+doc);
        System.out.println("\n-------------------------");
    }

}