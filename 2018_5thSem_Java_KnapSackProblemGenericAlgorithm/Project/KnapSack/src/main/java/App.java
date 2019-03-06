import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class App {

    /*public static void main(String args[]) {
        App app = new App("KnapSack/src/main/resources/FirstSet");
        try {
            ArrayList<Population> population = app.calculate();
            System.out.println(population);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }*/

    String fileName;
    KnapsackAlgorithm knapsackAlgorithm = new KnapsackAlgorithm();
    Population population;
    List<Item> items;
    int capacityOfKnapsack;
    int numberOfGenerations;
    int numberOfItems;
    int sizeOfpopulation;

    public App(String fileName) {
        this.fileName = fileName;
        items = new ArrayList<>();
    }

    public App(int capacityOfKnapsack, int numberOfGenerations, int numberOfItems, int sizeOfpopulation,
               List<Item> items) {
        this.capacityOfKnapsack = capacityOfKnapsack;
        this. numberOfGenerations = numberOfGenerations;
        this.sizeOfpopulation = sizeOfpopulation;
        this.numberOfItems = numberOfItems;
        this.items = new ArrayList<Item>(items);
    }

    public ArrayList<Population> calculateAgain(ArrayList<Population> pops, int moreGen) {
        int counter = 0;
        ArrayList<Population> populations = new ArrayList<>(pops);

        do {
            population = knapsackAlgorithm.processAlgorithm(population, items, capacityOfKnapsack);
            counter++;
            populations.add(population);
        } while (!(counter > moreGen));

        //while (!(counter > moreGen && (population.ifMostHaveSameValue())));

        return populations;
    }

    //jak uzywamy czytania z pliku
    public ArrayList<Population> calculate2() throws IOException {
        int counter = 0;
        ArrayList<Population> populations = new ArrayList<>();
        //creating items
        //items = new ArrayList<>();
        //items = fileParser.getItemArrayList();

        //creating population
        population = new Population(sizeOfpopulation);
        population.generateRandomPopulation(items.size());

        do {
            population = knapsackAlgorithm.processAlgorithm(population, items, capacityOfKnapsack);
            counter++;
            populations.add(population);
        } while (!(counter > numberOfGenerations ));

        //while (!(counter > numberOfGenerations && (population.ifMostHaveSameValue())));

        return populations;
    }

    public ArrayList<Population> calculate() throws IOException {

        int counter = 0;

        FileParser fileParser = new FileParser(fileName);
        fileParser.readItems();
        ArrayList<Population> populations = new ArrayList<>();
        //creating items
        //items = new ArrayList<>();
        items = fileParser.getItemArrayList();

        //creating population
        population = new Population(fileParser.getPopSize());
        population.generateRandomPopulation(fileParser.getItemArrayList().size());

        //zapisujemy, zeby potem nie trzeba bylo sie zastanawiac przy ponownym liczeniu
        sizeOfpopulation = fileParser.getPopSize();
        numberOfItems = fileParser.getItemArrayList().size();
        capacityOfKnapsack = fileParser.getKnapsackCapacity();

        do {
            population = knapsackAlgorithm.processAlgorithm(population, fileParser.getItemArrayList(),
                    fileParser.getKnapsackCapacity());
            counter++;
            populations.add(population);
        } while (!(counter > fileParser.getGenNumber()));

        //while (!(counter > fileParser.getGenNumber() && (population.ifMostHaveSameValue())));

        return populations;
    }
}