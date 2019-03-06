


import javafx.application.*;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

import javafx.scene.layout.VBox;
import javafx.stage.*;


public class MainView  extends Application{

    private static Stage window;
    private static Scene sceneMainMenu;


    public static void main(String args[]) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception{

        window = primaryStage;
        window.setTitle("Knapsack Problem Genetic Algorithm");

        Label label = new Label("MENU");
        Button buttonSetItems = new Button("Wprowadz recznie dane");
        Button buttonReadFromFile = new Button("Wprowadz dane z pliku");
        Button buttonShowResults = new Button("Wyswietl wyniki");
        Button buttonExit = new Button("EXIT");

        //glowna scena
        VBox layoutMainMenu = new VBox(10);
        layoutMainMenu.getChildren().addAll(label, buttonSetItems, buttonReadFromFile, buttonExit);
        layoutMainMenu.setAlignment(Pos.CENTER);
        sceneMainMenu = new Scene(layoutMainMenu, 300, 200);

        /*//wpisywanie reczne
        VBox layoutSetItems = new VBox(10);
        //layoutSetItems.getChildren().addAll(label, buttonSetItems, buttonReadFromFile, buttonExit);
        //layoutSetItems.setAlignment(Pos.CENTER);
        Scene sceneSetItems = new Scene(layoutSetItems, 500, 500);*/

        buttonSetItems.setOnAction(e -> SetItemsManuallyView.setSceneSetItemsManually());
        buttonReadFromFile.setOnAction(e -> ReadFromFileView.setSceneReadFromFile());
        buttonExit.setOnAction(e -> closeProgram());

        window.setOnCloseRequest( e -> {
                e.consume();
                closeProgram();
        });
        window.setScene(sceneMainMenu);
        window.show();

    }

    private void closeProgram() {
        Boolean result = ConfirmExit.display("Czy na pewno chcesz zamknac program ?");
        if(result)
            window.close();
    }

    public static Scene getSceneMainMenu() {
        return sceneMainMenu;
    }

    public static Stage getWindow() {
        return window;
    }
}
