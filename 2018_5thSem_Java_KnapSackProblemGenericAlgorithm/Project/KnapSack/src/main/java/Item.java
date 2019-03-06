public class Item {
    private int volume;
    private int benefit;

    public Item(int volume, int benefit) {
        this.volume = volume;
        this.benefit = benefit;
    }

    public int getVolume() {
        return volume;
    }

    public int getBenefit() {
        return benefit;
    }

    @Override
    public String toString() {
        return "Item{" +
                "volume=" + volume +
                ", benefit=" + benefit +
                '}';
    }
}
