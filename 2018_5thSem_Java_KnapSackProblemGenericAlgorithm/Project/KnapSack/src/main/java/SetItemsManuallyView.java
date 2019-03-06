import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;

import java.awt.event.ActionEvent;
import java.beans.EventHandler;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class SetItemsManuallyView {

    public static void setSceneSetItemsManually() {

        GridPane gridSetItemsManually = new GridPane();
        gridSetItemsManually.setPadding(new Insets(10, 10, 10, 10));
        gridSetItemsManually.setVgap(8);
        gridSetItemsManually.setHgap(8);

//--------------------------------------------------------------------------------------------------------------------
//---SCENA USTALANIA PARAMETROW-----------SCENA USTALANIA PARAMETROW---------------SCENA USTALANIA PARAMETROW---------
        Label numberOfItemsLabel = new Label("Ilosc przedmiotow");
        GridPane.setConstraints(numberOfItemsLabel, 0,0);
        TextField numberOfItemsTextField = new TextField();
        numberOfItemsTextField.setPromptText("Podaj ilosc przedmiotow");
        GridPane.setConstraints(numberOfItemsTextField, 1,0);

        Label sizeOfPopulationLabel = new Label("Rozmiar populacji");
        GridPane.setConstraints(sizeOfPopulationLabel, 0,1);
        TextField sizeOfPopulationTextField = new TextField();
        sizeOfPopulationTextField.setPromptText("Podaj rozmiar populacji");
        GridPane.setConstraints(sizeOfPopulationTextField, 1,1);

        Label numberOfGenerationsLabel = new Label("Ilosc generacji");
        GridPane.setConstraints(numberOfGenerationsLabel, 0,2);
        TextField numberOfGenerationsTextField = new TextField();
        numberOfGenerationsTextField.setPromptText("Podaj ilosc generacji");
        GridPane.setConstraints(numberOfGenerationsTextField, 1,2);

        Label capacityOfKnapsackLabel = new Label("Rozmiar plecaka");
        GridPane.setConstraints(capacityOfKnapsackLabel, 0,3);
        TextField capacityOfKnapsackTextField = new TextField();
        capacityOfKnapsackTextField.setPromptText("Podaj rozmiar plecaka");
        GridPane.setConstraints(capacityOfKnapsackTextField, 1,3);




        Button setNameOfFileButton = new Button("Zatwierdz");
        GridPane.setConstraints(setNameOfFileButton, 1,4);
        setNameOfFileButton.setOnAction( e -> {
            try {
                int capacityOfKnapsack = Integer.parseInt(capacityOfKnapsackTextField.getText());
                int numberOfGenerations = Integer.parseInt(numberOfGenerationsTextField.getText());;
                int sizeOfPopulation = Integer.parseInt(sizeOfPopulationTextField.getText());
                int numberOfItems = Integer.parseInt(numberOfItemsTextField.getText());

                SetItemDataView.setSceneSetItemData(capacityOfKnapsack, numberOfGenerations, sizeOfPopulation,
                                            numberOfItems);

                System.out.println(capacityOfKnapsack + " " + numberOfGenerations + " " + sizeOfPopulation + " " +
                        numberOfItems);

            } catch (NumberFormatException e1) {
                System.out.println(e1);
            }
        } );

        Button backToMainViewButton = new Button("Powrot do menu glownego");
        GridPane.setConstraints(backToMainViewButton, 1,6);
        backToMainViewButton.setOnAction(e -> MainView.getWindow().setScene(MainView.getSceneMainMenu()));
//---SCENA USTALANIA PARAMETROW-----------SCENA USTALANIA PARAMETROW---------------SCENA USTALANIA PARAMETROW---------
//--------------------------------------------------------------------------------------------------------------------


        gridSetItemsManually.getChildren().addAll(numberOfItemsLabel, numberOfItemsTextField, sizeOfPopulationLabel,
                sizeOfPopulationTextField, numberOfGenerationsLabel, numberOfGenerationsTextField,
                capacityOfKnapsackLabel, capacityOfKnapsackTextField, setNameOfFileButton, backToMainViewButton);
        Scene sceneSetItemsManually = new Scene(gridSetItemsManually, 300, 200);
        MainView.getWindow().setScene(sceneSetItemsManually);
    }
}
