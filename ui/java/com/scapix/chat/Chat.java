package com.scapix.chat;

public final class Chat
{
	static { System.loadLibrary("chatlib"); }
	public static void main(String args[])
	{
		System.out.println("0");

		Session session = new Session();
		Model model = new Model();
		Contact contact = new Contact();

		System.out.println("1");
		contact.name("hello world");
		System.out.println("2");
		System.out.println(contact.name());
		System.out.println(contact.deviceName());
		System.out.println("3");

		session.testException(() -> {
			session.throwException();
		});

		java.util.TreeMap<Integer,String> map2 = new java.util.TreeMap<Integer,String>();
		map2.put(1, "one");
		map2.put(2, "two");

		java.util.Map tree2 = session.map2(map2);
		System.out.println(tree2);

		java.util.TreeMap<Integer,Float> map3 = new java.util.TreeMap<Integer,Float>();
		map3.put(1, 1.1f);
		map3.put(2, 2.2f);

		java.util.Map tree3 = session.map3(map3);
		System.out.println(tree3);

		int[] myIntArray = {1,2,3};
		int[] ints = session.ints(myIntArray);
		System.out.println(java.util.Arrays.toString(ints));

		Element elem = new Element();
		elem.toString();
		elem.func1();

		ExtendedContact ex = new ExtendedContact();
//		ex.protectedFunc();
	}
}
