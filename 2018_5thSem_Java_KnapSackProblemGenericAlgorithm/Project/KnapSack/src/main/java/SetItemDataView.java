import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class SetItemDataView {

    public static void setSceneSetItemData(int capacityOfKnapsack, int numberOfGenerations, int sizeOfPopulation,
                                           int numberOfItems) {
        GridPane gridSetItemData = new GridPane();
        gridSetItemData.setPadding(new Insets(10, 10, 10, 10));
        gridSetItemData.setVgap(8);
        gridSetItemData.setHgap(8);

        Label informationLabel = new Label("Wypelnij dane przemiotow");
        GridPane.setConstraints(informationLabel, 1,0);


        Vector<TextField> volumes = new Vector<>();
        Vector<TextField> benefits = new Vector<>();

        for (int i = 0; i < numberOfItems ; i++) {
            Label volumeLabel = new Label("Objetosc przedmiotu nr " + (i+1));
            GridPane.setConstraints(volumeLabel, 0, 2*i+1 );
            TextField volumeTextField = new TextField();
            volumeTextField.setPromptText("Podaj objetosc przedmiotu nr " + (i+1));
            GridPane.setConstraints(volumeTextField, 1, 2*i+1);

            Label benefitLabel = new Label("Wartosc przedmiotu nr " + (i+1));
            GridPane.setConstraints(benefitLabel, 0, 2*i+2);
            TextField benefitTextField = new TextField();
            benefitTextField.setPromptText("Podaj Wartosc przedmiotu nr " + (i+1));
            GridPane.setConstraints(benefitTextField, 1, 2*i+2);

            volumes.add(volumeTextField);
            benefits.add(benefitTextField);

            gridSetItemData.getChildren().addAll(volumeLabel,volumeTextField,benefitLabel,benefitTextField);
        }

        //ekran w trakcie wykonywania algorytmu
        Label whileAlgorithmIsProceedLabel = new Label("Algorytm sie wykonuje");
        VBox layout = new VBox(10);
        layout.setAlignment(Pos.CENTER);
        layout.getChildren().add(whileAlgorithmIsProceedLabel);







        Button addItemsButton = new Button("ZATWIERDZ");
        GridPane.setConstraints(addItemsButton, 1,2*numberOfItems+2);
        addItemsButton.setOnAction(e -> {
            try {

                Scene sceneWhileAlgorithmIsProceed = new Scene(layout, 300, 200);
                MainView.getWindow().setScene(sceneWhileAlgorithmIsProceed);

                List<Item> items = new ArrayList<>();
                for (int i = 0; i < numberOfItems; i++) {
                    int volume = Integer.parseInt(volumes.get(i).getText());
                    int benefit = Integer.parseInt(benefits.get(i).getText());
                    Item item = new Item(volume, benefit);
                    items.add(item);
                }
                App app = new App(capacityOfKnapsack, numberOfGenerations, numberOfItems, sizeOfPopulation, items);
                ArrayList<Population> populations = app.calculate2();
                Chromosome tempChr = populations.get(populations.size()-1).getTheFittestChromosome();

                ChartView.drawChart(populations);
                ChartMaxView.drawChart(populations);

                MoreGenerationsView.setSceneMoreGenerations(populations, app);

                //wracamy do menu glownego
                //MainView.getWindow().setScene(MainView.getSceneMainMenu());
            } catch (NumberFormatException | IOException e1) {
                System.out.println(e1);
            }
        });

        Button backToMainViewButton = new Button("Powrot do menu glownego.");
        GridPane.setConstraints(backToMainViewButton, 1,2*numberOfItems+3);
        backToMainViewButton.setOnAction(e -> MainView.getWindow().setScene(MainView.getSceneMainMenu()));

        gridSetItemData.getChildren().addAll(informationLabel, addItemsButton, backToMainViewButton);
        Scene sceneSetItemData = new Scene(gridSetItemData, 400, numberOfItems*93);
        MainView.getWindow().setScene(sceneSetItemData);

    }
}
