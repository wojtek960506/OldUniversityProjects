import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Population {

    private int populationSize;
    private List<Chromosome> chromosomeList;

    public Population(int populationSize) {
        this.populationSize = populationSize;
        chromosomeList = new ArrayList<>();
    }

    public Population(int populationSize, List<Chromosome> chromosomeList) {
        this.populationSize = populationSize;
        this.chromosomeList = chromosomeList;
    }

    public void generateRandomPopulation(int chrSize) {
        //tutaj wczesniej bylo chrSize
        for (int i = 0; i < populationSize; i++) {
            Chromosome chr = new Chromosome(chrSize);
            chr.generateRandomChromosome();
            chromosomeList.add(chr);
        }
    }

    public int getPopulationSize() {
        return populationSize;
    }

    public List<Chromosome> getChromosomeList() {
        return chromosomeList;
    }

    public boolean ifMostHaveSameValue() {

        List<Chromosome> tempArrayList = new ArrayList<>(chromosomeList);
        Collections.sort(tempArrayList, new ChromosomeComparator());
        int currValue = chromosomeList.get(0).getChrTotalBenefit();
        int counter = 1;
        for (Chromosome chromosome : tempArrayList) {
            if (chromosome.getChrTotalBenefit() != currValue) {
                currValue = chromosome.getChrTotalBenefit();
                counter = 1;
            } else
                counter++;

            if (counter >= chromosomeList.size() * 0.9)
                return true;
        }
        return false;
    }

    public Chromosome getTheFittestChromosome() {
        List<Chromosome> tempArrayList = new ArrayList<>(chromosomeList);
        Collections.sort(tempArrayList, new ChromosomeComparator());
        //System.out.println(tempArrayList.get(0));
        return tempArrayList.get(0);
    }

    public double averageBenefit() {
        int counter = 0, sum = 0;
        for (Chromosome chromosome : this.chromosomeList) {
            counter++;
            sum += chromosome.getChrTotalBenefit();
        }
        return sum / counter;

    }

    public ArrayList<Chromosome> twoBestChromosomes() {
        ArrayList<Chromosome> bestChromosomes = new ArrayList<>(Arrays.asList(chromosomeList.get(0), chromosomeList.get(1)));
        for (Chromosome chromosome : this.chromosomeList) {
            if (chromosome.getChrTotalBenefit() > bestChromosomes.get(0).getChrTotalBenefit())
                bestChromosomes.set(0, chromosome);
        }
        for (Chromosome chromosome : this.chromosomeList) {
            if (chromosome.getChrTotalBenefit() > bestChromosomes.get(1).getChrTotalBenefit() && chromosome.getChrTotalBenefit() != bestChromosomes.get(0).getChrTotalBenefit())
                bestChromosomes.set(1, chromosome);
        }
        return bestChromosomes;
    }

    @Override
    public String toString() {
        return "Population{" +
                "chromosomeList=\n" + Arrays.toString(chromosomeList.toArray()) +
                '}';
    }
}
