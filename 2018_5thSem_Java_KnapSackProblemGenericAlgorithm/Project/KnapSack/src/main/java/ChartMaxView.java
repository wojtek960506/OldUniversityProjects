import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.util.ArrayList;

public class ChartMaxView {

    public static void drawChart(ArrayList<Population> arrayOfPopulations) {
        try {
            Stage stageMax = new Stage();
            stageMax.setTitle("Wykres maksymalnej wartsoci benefitu w kazdej populacji");
            //defining the axes
            final NumberAxis xAxis = new NumberAxis();
            final NumberAxis yAxis = new NumberAxis();
            xAxis.setLabel("Numer generacji");
            //creating the chart
            final LineChart<Number, Number> lineChart =
                    new LineChart<Number, Number>(xAxis, yAxis);

            lineChart.setTitle("Maksymalny benefit plecaka");
            //defining a series
            XYChart.Series seriesMax = new XYChart.Series();
            seriesMax.setName("Problem plecakowy - maksymalna wartosc");
            //App app = new App("KnapSack/src/main/resources/FirstSet");

            ArrayList<Population> populations = arrayOfPopulations;

            int counter = 1;
            for (Population population : populations) {
                //series.getData().add(new XYChart.Data(counter, population.averageBenefit()));
                seriesMax.getData().add(new XYChart.Data(counter, population.getTheFittestChromosome().getChrTotalBenefit()));
                counter++;

            }


            Scene scene2 = new Scene(lineChart, 800, 600);
            lineChart.getData().add(seriesMax);



            stageMax.setScene(scene2);
            stageMax.showAndWait();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
