

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javafx.application.*;
import javafx.event.*;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.*;


public class testFitnesu  extends Application{

    Button button;
    Stage window;
    Scene scene1, scene2;

    public static void main(String args[]) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception{

        window = primaryStage;
        window.setTitle("thenewboston");

        button = new Button("Click me.");
        button.setOnAction(e -> AlertBox.display("SIUSIAK", "Ale duzy"));


        StackPane layout = new StackPane();
        layout.getChildren().add(button);
        Scene scene = new Scene(layout, 300, 250);
        window.setScene(scene);
        window.show();

    }

    /*PRZELACZANIE MIEDZY SCENAMI

    primaryStage.setTitle("Title_of_the_Window");
        window = primaryStage;
        Button button1 = new Button("Go to scene 2");
        Label label1 = new Label("Welcome to the first scene");


        //lambda
        button1.setOnAction(e -> window.setScene(scene2));

        //Layout 1 - children are laid out in vertical column
        VBox layout1 = new VBox(20);
        layout1.getChildren().addAll(label1, button1);
        scene1 = new Scene(layout1, 200, 200);

        //Button2
        Button button2 = new Button("This scene sucks, go back to scene 1");
        button2.setOnAction(e -> window.setScene(scene1));

        //layout2
        StackPane layout2 = new StackPane();
        layout2.getChildren().add(button2);
        scene2 = new Scene(layout2, 600, 300);

        window.setScene(scene1);
        window.setTitle("Title here");
        window.show();
        */




    /*@Override
    public void handle(ActionEvent event) {
        if(event.getSource() == button) {
            System.out.println("Siusiak");
        }
        if(event.getSource() == button2) {
            System.out.println("Kutas");
        }
    }*/
}

/*App app = new App("KnapSack/src/main/resources/FirstSet");
        try {
            Population population = app.calculate();
            System.out.println(population.toString());
            //System.out.println(Arrays.toString(chromosomeList.toArray()));
        } catch (IOException e) {
            e.printStackTrace();
        }*/


        /*try {
            KnapsackAlgorithm k = new KnapsackAlgorithm();
            //List<Chromosome> population = new ArrayList<>();
            Population population;
            String fileName = "KnapSack/src/main/resources/FirstSet";

            ReadFromFile readFromFile = new ReadFromFile(fileName);
            readFromFile.readItems();

            int knapsackCapacity = readFromFile.getKnapsackCapacity();
            List<Item> items = readFromFile.getItemArrayList();

            population = new Population(6);
            population.generateRandomPopulation(readFromFile.getItemArrayList().size());

            System.out.println("POCZATKOWE");
            System.out.println(population.toString());

            k.fitnessCalcAll(population.getChromosomeList(), items, knapsackCapacity);
            System.out.println("PO FITNESIE");
            System.out.println(population.toString());

            population = k.groupSelection(population);
            System.out.println("PO GROUP SELECTION");
            System.out.println(population.toString());

            population = k.crossoverChromosomes(population,items,knapsackCapacity);
            System.out.println("PO CROSSOVER");
            System.out.println(population.toString());

            population = k.mutateChromosomes(population,items,knapsackCapacity);
            System.out.println("PO MUTATE");
            System.out.println(population.toString());


        } catch (IOException e) {
            e.printStackTrace();
        }*/


            /*for(int i=0; i<4 ; i++) {
                population.add(new Chromosome(6));
                population.get(i).generateRandomChromosome();
                population.get(i).fitnessCalculate(items,knapsackCapacity);
            }*/

            /*System.out.println(population.get(2).toString());

            population.get(2).setMutateGene(items );
            population.get(2).fitnessCalculate(items,knapsackCapacity);

            System.out.println("PO MUTACJI");

            System.out.println(population.get(2).toString());
*/
            /*System.out.println("PRZED WSZYSTKIM");
            System.out.println(Arrays.toString(population.toArray()));

            //for(int i=0 ; i<10;i++)  {
                //System.out.println(i);
                population = k.groupSelection(population);
                population = k.crossoverChromosome(population, items, knapsackCapacity);
                population = k.mutateChromosome(population,items,knapsackCapacity);
            //}
            //System.out.println(Arrays.toString(population.toArray()));

            //population = k.mutateChromosome(population,items,knapsackCapacity);




            //for(Chromosome chromosome : population)
              //  chromosome.fitnessCalculate(items,knapsackCapacity);

            System.out.println("PO WSZYSTKIM");
            System.out.println(Arrays.toString(population.toArray()));*/





            //System.out.println("Counter = " + counter);
            //System.out.println(Arrays.toString(population.toArray()));

           // System.out.println("\nPO MUTACJI\n");

            //k.mutateChromosome(population,items,knapsackCapacity);

            //System.out.println(Arrays.toString(population.toArray()));
            //System.out.println(knapsackCapacity);

            //for(Chromosome chr : population)
            /*for(int a=0;a<population.size();a++) {
                System.out.println("Chromosom nr " + a);
                System.out.println();
                population.get(a).fitnessCalculate(items, knapsackCapacity);
                //System.out.println(population.get(a).toString());
            }*/
            //if(k.ifMostHaveSameValue(population))
               // System.out.println("jest co najmniej 90%");
            //System.out.println("PO LICZENIU FITNESU");
            //System.out.println(Arrays.toString(population.toArray()));
            //System.out.println("totalVolume: " + c.getChrTotalVolume() + " totalBenefit: " + c.getChrTotalBenefit());

            //List<Chromosome> pop1 = k.groupSelection(population);


            //System.out.println(Arrays.toString(population.toArray()));

            //System.out.println("MAMAMA");

            //System.out.println(Arrays.toString(pop1.toArray()));





//*****************************************************************************************************
        //TO JEST GLOWNY TEST

        /*App app = new App("KnapSack/src/main/resources/FirstSet");
        try {
            List <Chromosome> chromosomeList = app.calcuate();
            //System.out.println(Arrays.toString(chromosomeList.toArray()));
        } catch (IOException e) {
            e.printStackTrace();
        }*/

//*************************************************************************************************

        /*List<Item> items = new ArrayList<Item>(Arrays.asList(new Item(20, 30),
                new Item(10, 50), new Item(5, 15), new Item(10, 13),
                new Item(3, 5)));
        //System.out.println(items.get(1).getBenefit());
        Population population = new Population(30);
        population.generateRandomPopulation(5);
        System.out.println(population.chromosomesFitness(items));
        System.out.println(population.toString());
        //Chromosome chr = new Chromosome(items.size());
        //chr.generateRandomChromosome();
        //int n = chr.fitnessCalculate(items);
        System.out.println(n);
        int[] b = chr.getGenes();
        for (int i : chr.getGenes())
            System.out.println(i);
        */

