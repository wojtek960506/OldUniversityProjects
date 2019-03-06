import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.util.ArrayList;

public class ChartView {

    public static void drawChart(ArrayList<Population> arrayOfPopulations) {
        try {
            Stage stage = new Stage();
            stage.setTitle("Wykres sredniej wartosci benefitu w kazdej generacji.");
            //defining the axes
            final NumberAxis xAxis = new NumberAxis();
            final NumberAxis yAxis = new NumberAxis();
            xAxis.setLabel("Numer generacji");
            //creating the chart
            final LineChart<Number, Number> lineChart =
                    new LineChart<Number, Number>(xAxis, yAxis);

            lineChart.setTitle("Sredni benefit plecaka");
            //defining a series
            XYChart.Series series = new XYChart.Series();
            series.setName("Problem plecakowy - srednia wartosc");
            //App app = new App("KnapSack/src/main/resources/FirstSet");

            ArrayList<Population> populations = arrayOfPopulations;

            int counter = 1;
            for (Population population : populations) {
                series.getData().add(new XYChart.Data(counter, population.averageBenefit()));
                //seriesMax.getData().add(new XYChart.Data(counter, population.getTheFittestChromosome().getChrTotalBenefit()));
                counter++;

            }

            Scene scene = new Scene(lineChart, 800, 600);
            lineChart.getData().add(series);


            stage.setScene(scene);
            //stage.showAndWait();
            stage.show();


        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
