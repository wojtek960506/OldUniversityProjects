import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;

public class FileParser {
    private String fileName;
    private int genNumber;
    private int popSize;
    private int knapsackCapacity;
    private List<Item> itemArrayList;

    public FileParser(String fileName) {
        this.fileName = fileName;
        itemArrayList = new ArrayList<>();
    }
    public void readItems() throws IOException {
        String content;
        File file = new File(fileName);
        List<String> list = new LinkedList<>();
        Scanner sc = new Scanner(new FileInputStream(file));
        while (sc.hasNextLine()){
            content = sc.nextLine();
            list.add(content);
        }
        sc.close();
        genNumber = Integer.parseInt(list.get(0).substring(0,list.get(0).indexOf(" ")));
        popSize = Integer.parseInt(list.get(0).substring(list.get(0).indexOf(" ")+1));
        knapsackCapacity = Integer.parseInt(list.get(1));
        for (int i = 2; i < list.size(); i++) {
            String temp = list.get(i);
            itemArrayList.add(new Item(Integer.parseInt(temp.substring(0,temp.indexOf(" "))),
                    Integer.parseInt(temp.substring(temp.indexOf(" ")+1))));
        }
    }

    public List<Item> getItemArrayList() {
        return itemArrayList;
    }

    public int getGenNumber() {
        return genNumber;
    }

    public int getPopSize() {
        return popSize;
    }

    public int getKnapsackCapacity() {
        return knapsackCapacity;
    }

    @Override
    public String toString() {
        return "FileParser{" +
                "fileName='" + fileName + '\'' +
                ", genNumber=" + genNumber +
                ", popSize=" + popSize +
                ", backPackCapacity=" + knapsackCapacity +
                ", itemArrayList=" + Arrays.toString(itemArrayList.toArray()) +
                '}';
    }
}
