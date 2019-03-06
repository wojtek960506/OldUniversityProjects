import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import javax.sound.midi.Soundbank;
import java.util.ArrayList;

public class ReadFromFileView {


    public static void setSceneReadFromFile() {

        GridPane gridReadFromFile = new GridPane();
        gridReadFromFile.setPadding(new Insets(10,10,10,10));
        //odleglosci w kracie
        gridReadFromFile.setVgap(8);
        gridReadFromFile.setHgap(8);

        Label nameOfFileLabel = new Label("Nazwa pliku");
        GridPane.setConstraints(nameOfFileLabel, 0,0);

        TextField nameOfFileTextField = new TextField();
        nameOfFileTextField.setPromptText("podaj nazwe pliku");
        GridPane.setConstraints(nameOfFileTextField, 1,0);


        //jak sie bedize liczylo
        Label whileAlgorithmIsProceedLabel = new Label("Algorytm sie wykonuje");
        VBox layout = new VBox(10);
        layout.setAlignment(Pos.CENTER);
        layout.getChildren().add(whileAlgorithmIsProceedLabel);

        Button setNameOfFileButton = new Button("Zatwierdz");
        GridPane.setConstraints(setNameOfFileButton, 1,1);
        setNameOfFileButton.setOnAction(e -> {
            String nameOfFile = nameOfFileTextField.getText();
            if(nameOfFile.equals("FirstSet")) {
                String filePath = "KnapSack/src/main/resources/";
                filePath += nameOfFile;

                Scene sceneWhileAlgorithmIsProceed = new Scene(layout, 300, 200);
                MainView.getWindow().setScene(sceneWhileAlgorithmIsProceed);

                App app = new App(filePath);
                try {
                    ArrayList<Population> populations = app.calculate();
                    Chromosome tempChr = populations.get(populations.size()-1).getTheFittestChromosome();

                    ChartView.drawChart(populations);
                    ChartMaxView.drawChart(populations);

                    MoreGenerationsView.setSceneMoreGenerations(populations, app);
                    //pytamy czy chcemy liczyc jeszcze raz
                    //Boolean result = ConfirmExit.display("Czy chcesz kontynuowac obliczenia ?");
                    //if(result) {
                        //MoreGenerationsView.setSceneMoreGenerations(populations, app);
                    //}

                    //MainView.getWindow().setScene(MainView.getSceneMainMenu());
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }


        });

        Button backToMainViewButton = new Button("Powrot do menu glownego");
        GridPane.setConstraints(backToMainViewButton, 1,5);
        backToMainViewButton.setOnAction(e -> MainView.getWindow().setScene(MainView.getSceneMainMenu()));

        //VBox layoutReadFromFile = new VBox(10);
        gridReadFromFile.getChildren().addAll(nameOfFileLabel, nameOfFileTextField, setNameOfFileButton, backToMainViewButton);
        Scene sceneReadFromFile = new Scene(gridReadFromFile, 300, 200);
        MainView.getWindow().setScene(sceneReadFromFile);
    }
}
