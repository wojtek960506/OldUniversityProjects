import java.util.Comparator;

public class ChromosomeComparator implements Comparator {
    @Override
    public int compare(Object o1, Object o2) {

        Chromosome chr1 = (Chromosome) o1;
        Chromosome chr2 = (Chromosome) o2;
        if (chr1.getChrTotalBenefit() > chr2.getChrTotalBenefit())
            return -1;
        else if (chr1.getChrTotalBenefit() < chr2.getChrTotalBenefit())
            return 1;
        else
            return 0;
    }
}
