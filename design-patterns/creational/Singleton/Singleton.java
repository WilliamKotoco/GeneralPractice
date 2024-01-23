public class Singleton {
  private static Singleton instance;
  public String value;

  /// Private constructor
  private Singleton(String value)
  {
    this.value = value;
  }

  /// Constructor available for public
  public static Singleton getInstance(String value)
  {
    if (instance == null)
      instance = new Singleton(value);
    return instance;

  }
}
