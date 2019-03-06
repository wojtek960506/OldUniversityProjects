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

public class MoreGenerationsView {

    public static void setSceneMoreGenerations(ArrayList<Population> pops, App app) {

        Boolean result = ConfirmExit.display("Czy chcesz kontynuowac obliczenia ?");
        //System.out.println("Rezultat: " + result);
        if(result) {

            GridPane gridMoreGenerations = new GridPane();
            gridMoreGenerations.setPadding(new Insets(10, 10, 10, 10));
            gridMoreGenerations.setVgap(8);
            gridMoreGenerations.setHgap(8);


            //EKRAN PONOWNEGO PRZELICZENIA
            Label moreGenerationsLabel = new Label("Dodatkowa ilosc generacji");
            GridPane.setConstraints(moreGenerationsLabel, 0, 1);
            TextField moreGenerationsTextField = new TextField();
            GridPane.setConstraints(moreGenerationsTextField, 1, 1);
            moreGenerationsTextField.setPromptText("Podaj dodatkowa ilosc generacji ");

            Button moreGenerationsButton = new Button("Zatwierdz");
            GridPane.setConstraints(moreGenerationsButton, 1, 2);
            moreGenerationsButton.setOnAction(e -> {
                try {
                    int moreGenerations = Integer.parseInt(moreGenerationsTextField.getText());

                    //System.out.println(moreGenerations);

                    ArrayList<Population> populations = app.calculateAgain(pops, moreGenerations);
                    Chromosome tempChr = populations.get(populations.size() - 1).getTheFittestChromosome();

                    ChartView.drawChart(populations);
                    ChartMaxView.drawChart(populations);

                    MoreGenerationsView.setSceneMoreGenerations(populations, app);


                    //wracamy do menu glownego
                    //MainView.getWindow().setScene(MainView.getSceneMainMenu());
                } catch (NumberFormatException e1) {
                    System.out.println(e1);
                }
            });

            Button backToMainViewButton = new Button("Powrot do menu glownego.");
            GridPane.setConstraints(backToMainViewButton, 1, 5);
            backToMainViewButton.setOnAction(e -> MainView.getWindow().setScene(MainView.getSceneMainMenu()));

            VBox moreGenerationsLayout = new VBox(10);
            moreGenerationsLayout.setAlignment(Pos.CENTER);
            moreGenerationsLayout.getChildren().addAll(moreGenerationsLabel, moreGenerationsTextField, moreGenerationsButton);


            gridMoreGenerations.getChildren().addAll(moreGenerationsLabel, moreGenerationsTextField, moreGenerationsButton,
                    backToMainViewButton);
            Scene sceneMoreGenerations = new Scene(gridMoreGenerations, 300, 200);
            MainView.getWindow().setScene(sceneMoreGenerations);
        } else {
            MainView.getWindow().setScene(MainView.getSceneMainMenu());
        }

    }
}
