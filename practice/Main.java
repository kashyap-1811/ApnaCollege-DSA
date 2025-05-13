// package threads;

// Using join() to wait for threads to finish.
class NewThread2 implements Runnable {

	String name; // name of thread
	Thread t;

	NewThread2(String threadname) {
		name = threadname;
		t = new Thread(this, name);
		System.out.println("New thread: " + t);
		t.start(); // Start the thread
		//t.run();
	}
// This is the entry point for thread.

	public void run() {
		try {
			for (int i = 5; i > 0; i--) {
				System.out.println(name + ": " + i);
				if (name.equals("One"))
					Thread.sleep(1000);
				else
					Thread.sleep(500);

                if(i == 3)  notify();
			}
		} catch (InterruptedException e) {
			System.out.println(name + " interrupted.");
		}
		System.out.println(name + " exiting.");
	}
}

public class Main {

	public static void main(String args[]) {
		NewThread2 ob1 = new NewThread2("One");
		NewThread2 ob2 = new NewThread2("Two");
		NewThread2 ob3 = new NewThread2("Three");
		System.out.println("Thread One is alive: " + ob1.t.isAlive());
		System.out.println("Thread Two is alive: " + ob2.t.isAlive());
		System.out.println("Thread Three is alive:" + ob3.t.isAlive());
		// wait for threads to finish
		try {
			System.out.println("Waiting for threads to finish.");
			ob1.t.join();
			System.out.println("Thread " + ob1.t.getName() + " joined");
			ob2.t.join();
			System.out.println("Thread " + ob2.t.getName() + " joined");
			ob3.t.join();
			System.out.println("Thread " + ob3.t.getName() + " joined");
		} catch (InterruptedException e) {
			System.out.println("Main thread Interrupted");
		}
		System.out.println("Thread One is alive: " + ob1.t.isAlive());
		System.out.println("Thread Two is alive: " + ob2.t.isAlive());
		System.out.println("Thread Three is alive: " + ob3.t.isAlive());
		System.out.println("Main thread exiting.");
	}
}