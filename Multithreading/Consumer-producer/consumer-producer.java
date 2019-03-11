public class ProducerConsumer {

    public static void main(String[] args) {

        class Shared {
            public int buf = 0;
            public int p = 0;
            public int c = 0;

        }

        class Producer extends Thread {

            private Shared s;

            public Producer(Shared s) {
                this.s = s;
            }

            public void run() {
                int[] a = { 2, 3, 1 };
                while (this.s.p < 3) {
                    while (this.s.p == this.s.c) {
                        this.s.buf = a[this.s.p];
                        System.out.println("Producer set item " + (this.s.p + 1) + " to " + a[this.s.p]);
                        this.s.p = this.s.p + 1;
                    }
                }
            }
        }

        class Consumer extends Thread {

            private Shared s;

            public Consumer(Shared s) {
                this.s = s;
            }

            public void run() {
                int[] b = { 0, 0, 0 };
                while (this.s.c < 3) {
                    while (this.s.p > this.s.c) {
                        b[this.s.c] = this.s.buf;
                        System.out.println("consumer set item " + (this.s.c + 1) + " to " + b[this.s.c]);
                        this.s.c = this.s.c + 1;
                    }
                }
            }

        }

        Shared share = new Shared();

        Producer p = new Producer(share);
        p.start();
        Consumer c = new Consumer(share);
        c.start();
    }
}
