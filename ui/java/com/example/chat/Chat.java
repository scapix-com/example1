package com.example.chat;

public final class Chat
{
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

		Struct2 s2 = new Struct2();
		s2.strings = new String[]{"string1", "string2"};
		s2.callback = (String s) -> {
			System.out.println("from java callback: " + s);
			return "returned from java callback";
		};
		s2.f1 = new Struct1();
		s2.f1.a = 33;
		s2.f1.b = "hello struct";
		s2.f1.buffer = new int[]{44, 55, 66};
		Struct1 s1 = model.testStruct(s2);
		System.out.println("s1.a=" + s1.a + ", s1.b=" + s1.b + ", s1.buffer=" + java.util.Arrays.toString(s1.buffer));
	}
}
